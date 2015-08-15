## 介绍

TBJSONModel是一个方便你快速创建数据Model的库。TBJSONModel会自动根据当前Model的属性来解析JSON的字典对象。借鉴了[JSONModel](https://github.com/icanzilb/JSONModel)和[Mantle](https://github.com/github/Mantle)。

在获取当前Model属性的信息时使用到了objc runtime的接口，每一个属性都使用一个 `TBJSONModelProperty` 对象来描述。如果某个Model的属性是一个数组，而数组的每一个元素是另一个Model类型的对象时候，则使用Protocol的方式来声明数组元素的类型， 比如:

 	@property (nonatomic, strong) NSArray<TBTestModel> *testModels;

这样TBJSONModel会将json数组对应的每一个元素都解析成TBTestModel对象。同理如果某个字典，所有key对应的object为某个特定类型的Model的对象也是通过这样的方式进行指定的。

## 要求


- ARC
- iOS 4.3

## 特点

- 属性自动映射设置。如果json对象和model对象的属性名一致的情况，model通过json对象初始化后，会自动设置到对应的属性上，当然也可以通过key map的机制，自定义映射规则，这种多数用于json对象属性为objc保留字的情况。在自动映射时会忽略只读属性。

- 类型智能转换。主要是当model的属性为原始类型，比如整型，浮点型，BOOL类型，而json对象对应的属性为字符串的时候，会自动帮助将string转换到对应的原始类型；当model的属性类型为NSString而对应的数据为非NSString类型的时候也会进行自动转换；当model属性类型为NSNumber类型而对应的数据的类型为NSString的时候，依然会为你做自动转换。

- 通过Protocol声明的方式指定数据容器中单个元素的类型，也就是model属性为数组或者字典的时候，可以通过protocol的方式指定数组或者字典的元素的类型，TBJSONModel会对protocol的类型进行解析，得到对应的类。这里的Protocol需要和元素里面对应的Model类同名，只是用于指明里面元素的类名，没有其他作用。


## 范例

这里就举个简单的例子来说明TBJSONModel的使用方法，假设有如下一个json对象:

	{
	  "name": "testModel",
	  "descriotion": "这是一个简单的Model",
	  "subModels": [
	    {
	      "name": "subModel1",
	      "descriotion": "第一个子Model"
	    },
	    {
	      "name": "subModel2",
	      "descriotion": "第二个子Model"
	    }
	  ]
	}


这里你会发现当前json对象的subModels字段是一个数组，数组中的每一个元素又是一个和当前json对象类型一样的对象，如果使用TBJSONModel的方式来写对应的objc的数据Model类，则如下

TBTestModel.h

	#import <Foundation/Foundation.h>
	#import "TBJSONModel.h"

	@protocol TBTestModel <NSObject>
	@end

	@interface TBTestModel : TBJSONModel

	@property (nonatomic, copy) NSString *name;
	@property (nonatomic, copy) NSString *descriotion_;
	@property (nonatomic, strong) NSArray<TBTestModel> *subModels;

	@end


TBTestModel.m

	#import "TBTestModel.h"

	@implementation TBTestModel

	+ (TBJSONModelKeyMapper *)modelKeyMapper{
    	return [[TBJSONModelKeyMapper alloc] initWithDictionary:@{@"description":@"description_"}];
	}

	@end


对`descriotion`做了一个映射是因为descriotion在NSObject是一个特殊的函数，需要规避。

如果你使用的TBJSONModel的版本 >= 0.0.3的情况 ，可以覆盖另一个方法来实现同样的目的。

	+ (NSDictionary *)jsonToModelKeyMapDictionary{
		return @{@"description":@"description_"};
	}

覆盖此方法返回映射字典会简单很多。