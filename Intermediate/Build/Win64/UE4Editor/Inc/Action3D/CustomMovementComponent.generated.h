// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ACTION3D_CustomMovementComponent_generated_h
#error "CustomMovementComponent.generated.h already included, missing '#pragma once' in CustomMovementComponent.h"
#endif
#define ACTION3D_CustomMovementComponent_generated_h

#define Action3D_Source_Action3D_CustomMovementComponent_h_17_SPARSE_DATA
#define Action3D_Source_Action3D_CustomMovementComponent_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndCrouch); \
	DECLARE_FUNCTION(execStartCrouch);


#define Action3D_Source_Action3D_CustomMovementComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndCrouch); \
	DECLARE_FUNCTION(execStartCrouch);


#define Action3D_Source_Action3D_CustomMovementComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomMovementComponent(); \
	friend struct Z_Construct_UClass_UCustomMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UCustomMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Action3D"), NO_API) \
	DECLARE_SERIALIZER(UCustomMovementComponent)


#define Action3D_Source_Action3D_CustomMovementComponent_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUCustomMovementComponent(); \
	friend struct Z_Construct_UClass_UCustomMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UCustomMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Action3D"), NO_API) \
	DECLARE_SERIALIZER(UCustomMovementComponent)


#define Action3D_Source_Action3D_CustomMovementComponent_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomMovementComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomMovementComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMovementComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomMovementComponent(UCustomMovementComponent&&); \
	NO_API UCustomMovementComponent(const UCustomMovementComponent&); \
public:


#define Action3D_Source_Action3D_CustomMovementComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomMovementComponent(UCustomMovementComponent&&); \
	NO_API UCustomMovementComponent(const UCustomMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMovementComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCustomMovementComponent)


#define Action3D_Source_Action3D_CustomMovementComponent_h_17_PRIVATE_PROPERTY_OFFSET
#define Action3D_Source_Action3D_CustomMovementComponent_h_14_PROLOG
#define Action3D_Source_Action3D_CustomMovementComponent_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_PRIVATE_PROPERTY_OFFSET \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_SPARSE_DATA \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_RPC_WRAPPERS \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_INCLASS \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Action3D_Source_Action3D_CustomMovementComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_PRIVATE_PROPERTY_OFFSET \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_SPARSE_DATA \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_INCLASS_NO_PURE_DECLS \
	Action3D_Source_Action3D_CustomMovementComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACTION3D_API UClass* StaticClass<class UCustomMovementComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Action3D_Source_Action3D_CustomMovementComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
