//
//  UMClassInfo.h
//  UMBasis <https://github.com/umeye>
//
//  Created by Fred on 15/5/10.
//  Copyright (c) 2020 UMEYE.COM.
//
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, UMEncodingType) {
    UMEncodingTypeMask       = 0xFF, ///< mask of type value
    UMEncodingTypeUnknown    = 0, ///< unknown
    UMEncodingTypeVoid       = 1, ///< void
    UMEncodingTypeBool       = 2, ///< bool
    UMEncodingTypeInt8       = 3, ///< char / BOOL
    UMEncodingTypeUInt8      = 4, ///< unsigned char
    UMEncodingTypeInt16      = 5, ///< short
    UMEncodingTypeUInt16     = 6, ///< unsigned short
    UMEncodingTypeInt32      = 7, ///< int
    UMEncodingTypeUInt32     = 8, ///< unsigned int
    UMEncodingTypeInt64      = 9, ///< long long
    UMEncodingTypeUInt64     = 10, ///< unsigned long long
    UMEncodingTypeFloat      = 11, ///< float
    UMEncodingTypeDouble     = 12, ///< double
    UMEncodingTypeLongDouble = 13, ///< long double
    UMEncodingTypeObject     = 14, ///< id
    UMEncodingTypeClass      = 15, ///< Class
    UMEncodingTypeSEL        = 16, ///< SEL
    UMEncodingTypeBlock      = 17, ///< block
    UMEncodingTypePointer    = 18, ///< void*
    UMEncodingTypeStruct     = 19, ///< struct
    UMEncodingTypeUnion      = 20, ///< union
    UMEncodingTypeCString    = 21, ///< char*
    UMEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    UMEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    UMEncodingTypeQualifierConst  = 1 << 8,  ///< const
    UMEncodingTypeQualifierIn     = 1 << 9,  ///< in
    UMEncodingTypeQualifierInout  = 1 << 10, ///< inout
    UMEncodingTypeQualifierOut    = 1 << 11, ///< out
    UMEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    UMEncodingTypeQualifierByref  = 1 << 13, ///< byref
    UMEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    UMEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    UMEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    UMEncodingTypePropertyCopy         = 1 << 17, ///< copy
    UMEncodingTypePropertyRetain       = 1 << 18, ///< retain
    UMEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    UMEncodingTypePropertyWeak         = 1 << 20, ///< weak
    UMEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    UMEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    UMEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

/**
 Get the type from a Type-Encoding string.
 
 @param typeEncoding  A Type-Encoding string.
 @return The encoding type.
 */
UMEncodingType UMEncodingGetType(const char *typeEncoding);


/**
 Instance variable information.
 */
@interface UMClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) UMEncodingType type;    ///< Ivar's type

/**
 Creates and returns an ivar info object.
 
 @param ivar ivar opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface UMClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

/**
 Creates and returns a method info object.
 
 @param method method opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface UMClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) UMEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

/**
 Creates and returns a property info object.
 
 @param property property opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface UMClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) UMClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, UMClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, UMClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, UMClassPropertyInfo *> *propertyInfos; ///< properties

/**
 If the class is changed (for example: you add a method to this class with
 'class_addMethod()'), you should call this method to refresh the class info cache.
 
 After called this method, `needUpdate` will returns `YES`, and you should call 
 'classInfoWithClass' or 'classInfoWithClassName' to get the updated class info.
 */
- (void)setNeedUpdate;

/**
 If this method returns `YES`, you should stop using this instance and call
 `classInfoWithClass` or `classInfoWithClassName` to get the updated class info.
 
 @return Whether this class info need update.
 */
- (BOOL)needUpdate;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param cls A class.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param className A class name.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
