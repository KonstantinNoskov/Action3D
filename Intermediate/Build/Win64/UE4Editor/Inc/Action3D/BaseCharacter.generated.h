// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ACTION3D_BaseCharacter_generated_h
#error "BaseCharacter.generated.h already included, missing '#pragma once' in BaseCharacter.h"
#endif
#define ACTION3D_BaseCharacter_generated_h

#define Action3D_Source_Action3D_BaseCharacter_h_25_SPARSE_DATA
#define Action3D_Source_Action3D_BaseCharacter_h_25_RPC_WRAPPERS
#define Action3D_Source_Action3D_BaseCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS
#define Action3D_Source_Action3D_BaseCharacter_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseCharacter(); \
	friend struct Z_Construct_UClass_ABaseCharacter_Statics; \
public: \
	DECLARE_CLASS(ABaseCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Action3D"), NO_API) \
	DECLARE_SERIALIZER(ABaseCharacter)


#define Action3D_Source_Action3D_BaseCharacter_h_25_INCLASS \
private: \
	static void StaticRegisterNativesABaseCharacter(); \
	friend struct Z_Construct_UClass_ABaseCharacter_Statics; \
public: \
	DECLARE_CLASS(ABaseCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Action3D"), NO_API) \
	DECLARE_SERIALIZER(ABaseCharacter)


#define Action3D_Source_Action3D_BaseCharacter_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseCharacter(ABaseCharacter&&); \
	NO_API ABaseCharacter(const ABaseCharacter&); \
public:


#define Action3D_Source_Action3D_BaseCharacter_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseCharacter(ABaseCharacter&&); \
	NO_API ABaseCharacter(const ABaseCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseCharacter)


#define Action3D_Source_Action3D_BaseCharacter_h_25_PRIVATE_PROPERTY_OFFSET
#define Action3D_Source_Action3D_BaseCharacter_h_22_PROLOG
#define Action3D_Source_Action3D_BaseCharacter_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Action3D_Source_Action3D_BaseCharacter_h_25_PRIVATE_PROPERTY_OFFSET \
	Action3D_Source_Action3D_BaseCharacter_h_25_SPARSE_DATA \
	Action3D_Source_Action3D_BaseCharacter_h_25_RPC_WRAPPERS \
	Action3D_Source_Action3D_BaseCharacter_h_25_INCLASS \
	Action3D_Source_Action3D_BaseCharacter_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Action3D_Source_Action3D_BaseCharacter_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Action3D_Source_Action3D_BaseCharacter_h_25_PRIVATE_PROPERTY_OFFSET \
	Action3D_Source_Action3D_BaseCharacter_h_25_SPARSE_DATA \
	Action3D_Source_Action3D_BaseCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	Action3D_Source_Action3D_BaseCharacter_h_25_INCLASS_NO_PURE_DECLS \
	Action3D_Source_Action3D_BaseCharacter_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACTION3D_API UClass* StaticClass<class ABaseCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Action3D_Source_Action3D_BaseCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
