//
//  TBJSONModel.m
//  TBJSONModel
//
//  Created by Luke on 7/25/13.
//  Copyright (c) 2013 taobao. All rights reserved.
//

#import "TBJSONModel.h"
#import <objc/runtime.h>
#import "NSArray+TBJSONModel.h"
#import "NSDictionary+TBJSONModel.h"
#import "TBJSONModelKeyMapper.h"
#import "TBJSONModelProperty.h"
#import "TBJSONModelError.h"


NSString * const TBJSONModelBoolStringTrue = @"true";
NSString * const TBJSONModelBoolStringFalse = @"false";



//下面两个静态无需初始化，因为用于关联对象的key的时候只会用到其地址
static const char * kAssociatedMapperKey;
static const char * kAssociatedPropertiesKey;

@interface TBJSONModel(){
    BOOL _treatBoolAsStringWhenModelToJSON;
}

@end

@implementation TBJSONModel

#pragma mark -
#pragma mark Private 
- (void)_setupKeyMapper{
    if (objc_getAssociatedObject(self.class, &kAssociatedMapperKey) == nil) {
        TBJSONModelKeyMapper *keyMapper = [self.class modelKeyMapper];
        if (keyMapper != nil) {
            objc_setAssociatedObject(self.class, &kAssociatedMapperKey, keyMapper, OBJC_ASSOCIATION_RETAIN);
        }
    }
}

- (void)_setupPropertyMap{
    if (objc_getAssociatedObject(self.class, &kAssociatedPropertiesKey) == nil) {
     
        NSMutableDictionary *propertyMap = [NSMutableDictionary dictionary];
        
        Class class = [self class];

        while (class != [TBJSONModel class]) {
            unsigned int propertyCount;
            objc_property_t *properties = class_copyPropertyList(class, &propertyCount);
            for (unsigned int i = 0; i < propertyCount; i++) {
                
                objc_property_t property = properties[i];
                const char *propertyName = property_getName(property);
                NSString *name = [NSString stringWithUTF8String:propertyName];                
                //属性的相关属性都在propertyAttrs中，包括其类型，protocol，存取修饰符等信息
                const char *propertyAttrs = property_getAttributes(property);
                NSString *typeString = [NSString stringWithUTF8String:propertyAttrs];
                TBJSONModelProperty *modelProperty = [[TBJSONModelProperty alloc] initWithName:name typeString:typeString];
                if (!modelProperty.isReadonly) {
                    [propertyMap setValue:modelProperty forKey:modelProperty.name];
                }
            }
            free(properties);

            class = [class superclass];
        }
        objc_setAssociatedObject(self.class, &kAssociatedPropertiesKey, propertyMap, OBJC_ASSOCIATION_RETAIN);
    }
}


//根据对应的属性类型，将value进行转换成合适的值
- (id)valueForProperty:(TBJSONModelProperty *)property withJSONValue:(id)value{
    id resultValue = value;
    if (value == nil || [value isKindOfClass:[NSNull class]]) {
        resultValue = nil;
    }else{
        if (property.valueType != TBClassPropertyTypeObject) {
            /*当属性为原始数据类型而对应的json dict中的value的类型为字符串对象的时候
            则对字符串进行相应的转换*/
            if ([value isKindOfClass:[NSString class]]) {
                if (property.valueType == TBClassPropertyTypeInt ||
                    property.valueType == TBClassPropertyTypeUnsignedInt||
                    property.valueType == TBClassPropertyTypeShort||
                    property.valueType == TBClassPropertyTypeUnsignedShort) {
                    resultValue = [NSNumber numberWithInt:[(NSString *)value intValue]];
                }
                if (property.valueType == TBClassPropertyTypeLong ||
                          property.valueType == TBClassPropertyTypeUnsignedLong ||
                          property.valueType == TBClassPropertyTypeLongLong ||
                          property.valueType == TBClassPropertyTypeUnsignedLongLong){
                    resultValue = [NSNumber numberWithLongLong:[(NSString *)value longLongValue]];
                }
                if (property.valueType == TBClassPropertyTypeFloat) {
                    resultValue = [NSNumber numberWithFloat:[(NSString *)value floatValue]];
                }
                if (property.valueType == TBClassPropertyTypeDouble) {
                    resultValue = [NSNumber numberWithDouble:[(NSString *)value doubleValue]];
                }
                if (property.valueType == TBClassPropertyTypeChar) {
                    //对于BOOL而言，@encode(BOOL) 为 c 也就是signed char
                    resultValue = [NSNumber numberWithBool:[(NSString *)value boolValue]];
                }
            }
        }else{
            Class valueClass = property.objectClass;
            //当当前属性为TBJSONModel类型
            if ([valueClass isSubclassOfClass:[TBJSONModel class]] &&
                [value isKindOfClass:[NSDictionary class]]) {
                resultValue = [[valueClass alloc] initWithJSONDictionary:value];
            }
            
            //当当前属性为NSString类型，而对应的json的value为非NSString对象，自动进行转换
            if ([valueClass isSubclassOfClass:[NSString class]] &&
                ![value isKindOfClass:[NSString class]]) {
                resultValue = [NSString stringWithFormat:@"%@",value];
            }
            
            //当当前属性为NSNumber类型，而对应的json的value为NSString的时候
            if ([valueClass isSubclassOfClass:[NSNumber class]] &&
                [value isKindOfClass:[NSString class]]) {
                NSNumberFormatter *numberFormatter = [[NSNumberFormatter alloc] init];
                [numberFormatter setNumberStyle:NSNumberFormatterDecimalStyle];
                resultValue = [numberFormatter numberFromString:value];
            }
            
            NSString *valueProtocol = [property.objectProtocols lastObject];
            if ([valueProtocol isKindOfClass:[NSString class]]) {
                Class valueProtocolClass = NSClassFromString(valueProtocol);
                if (valueProtocolClass != nil) {
                    if ([valueProtocolClass isSubclassOfClass:[TBJSONModel class]]) {
                        //array of models
                        if ([value isKindOfClass:[NSArray class]]) {
                            resultValue = [(NSArray *)value modelArrayWithClass:valueProtocolClass];
                        }
                        //dictionary of models
                        if ([value isKindOfClass:[NSDictionary class]]) {
                            resultValue = [(NSDictionary *)value modelDictionaryWithClass:valueProtocolClass];
                        }
                    }
                }
            }
        }
    }
    return resultValue;
}

#pragma mark -
#pragma mark Class Method
+ (id)modelWithJSONDictionary:(NSDictionary *)dict{
    return [self modelWithJSONDictionary:dict error:NULL];
}

+ (id)modelWithJSONDictionary:(NSDictionary *)dict error:(NSError *__autoreleasing *)error{
    return [[self alloc] initWithJSONDictionary:dict error:error];
}

#pragma mark -
#pragma mark Init
- (id)init{
    self = [super init];
    if (self != nil) {
        [self _setupKeyMapper];
        [self _setupPropertyMap];
    }
    return self;
}

- (id)initWithJSONDictionary:(NSDictionary *)dict{
    return [self initWithJSONDictionary:dict error:NULL];
}

- (id)initWithJSONDictionary:(NSDictionary *)dict error:(NSError *__autoreleasing *)error{
    
    if (!dict) {
        if (error) {
            *error = [TBJSONModelError errorNilInput];
        }
        return nil;
    }
    
    if (![dict isKindOfClass:[NSDictionary class]]) {
        if (error) {
            *error = [TBJSONModelError errorDataInvalidWithDescription:@"输入参数类型数错，应该为NSDictionary"];
        }
        return nil;
    }
    
    self = [self init];
    if (self != nil) {
        NSDictionary *propertyMap = objc_getAssociatedObject(self.class, &kAssociatedPropertiesKey);
        TBJSONModelKeyMapper *keyMapper = objc_getAssociatedObject(self.class, &kAssociatedMapperKey);

        //对JSON所有字段进行遍历，到 keyMapper 中查看是否有映射的属性名，然后再对属性进行设置
        [dict enumerateKeysAndObjectsUsingBlock:^(NSString *jsonKey, id jsonValue, BOOL *stop) {
            NSString *propertyKey = keyMapper ? [keyMapper modelKeyMappedFromJsonKey:jsonKey] : jsonKey;
            TBJSONModelProperty *modelProperty = [propertyMap valueForKey:propertyKey];
            if (modelProperty) {
                id propertyValue = [self valueForProperty:modelProperty withJSONValue:jsonValue];
                if (propertyValue != nil) {
                    [self setValue:propertyValue forKey:modelProperty.name];
                }
            }
        }];
    }
    return self;
}

- (NSDictionary *)toJSONDictionary{
    NSDictionary *propertyMap = objc_getAssociatedObject(self.class, &kAssociatedPropertiesKey);
    if (propertyMap!= nil && [propertyMap count] > 0) {
        NSMutableDictionary *jsonDictionary = [NSMutableDictionary dictionaryWithCapacity:[propertyMap count]];
        TBJSONModelKeyMapper *keyMapper = objc_getAssociatedObject(self.class, &kAssociatedMapperKey);

        for (TBJSONModelProperty *property in [propertyMap allValues]) {
            NSString *dictKey = property.name;
            id val = [self valueForKeyPath:dictKey];
            
            if ([val isKindOfClass:[TBJSONModel class]]) {
                val = [(TBJSONModel *)val toJSONDictionary];
            }else if([val isKindOfClass:[NSArray class]]){
                val = [(NSArray *)val toJSONArray];
            }else if([val isKindOfClass:[NSDictionary class]]){
                val = [(NSDictionary *)val toJSONDictionary];
            }
            
            if (keyMapper != nil) {
                NSString *mappedKey = [keyMapper jsonKeyMappedFromModelKey:dictKey];
                if (mappedKey != nil) {
                    dictKey = mappedKey;
                }
            }

            if (val != nil && dictKey != nil) {
                if (property.valueType == TBClassPropertyTypeChar) {
                    if (_treatBoolAsStringWhenModelToJSON &&
                        [val isKindOfClass:[NSNumber class]]) {
                        NSString *booleanString = nil;
                        if ([val boolValue]) {
                            booleanString = TBJSONModelBoolStringTrue;
                        }else{
                            booleanString = TBJSONModelBoolStringFalse;
                        }
                        [jsonDictionary setObject:booleanString forKey:dictKey];
                    }else{
                        [jsonDictionary setObject:val forKey:dictKey];
                    }
                }else{
                    [jsonDictionary setObject:val forKey:dictKey];
                }
            }
        }
        return jsonDictionary;
    }
    return nil;
}

- (void)setTreatBoolAsStringWhenModelToJSON:(BOOL)treatBoolAsStringWhenModelToJSON{
    _treatBoolAsStringWhenModelToJSON = treatBoolAsStringWhenModelToJSON;
}

- (id)copyWithZone:(NSZone *)zone {
	return [[self.class allocWithZone:zone] initWithJSONDictionary:[self toJSONDictionary] error:NULL];
}

#pragma mark -
#pragma mark Key-Value Coding

- (void)setValue:(id)value forUndefinedKey:(NSString *)key {
    NSLog(@"WARNING: [%@] Set value:%@ for undefiend key: %@",NSStringFromClass(self.class) ,value, key);
}

- (id)valueForUndefinedKey:(NSString *)key {
    NSLog(@"WARNING: [%@] Get value for undefiend key %@", self, key);
    return nil;
}

- (void)setNilValueForKey:(NSString *)key{
    NSLog(@"WARNING: set nil value for key %@", key);
}

- (NSString *)description{
    return [NSString stringWithFormat:@"%@",[self toJSONDictionary]];
}

+ (TBJSONModelKeyMapper *)modelKeyMapper{
    NSDictionary *modelKeyMap = [self jsonToModelKeyMapDictionary];
    if (modelKeyMap) {
        return [[TBJSONModelKeyMapper alloc] initWithDictionary:modelKeyMap];
    } else {
        return nil;
    }
}

+ (NSDictionary *)jsonToModelKeyMapDictionary{
    return nil;
}
@end
