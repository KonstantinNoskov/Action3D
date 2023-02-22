// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Action3D/CustomMovementComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMovementComponent() {}
// Cross Module References
	ACTION3D_API UClass* Z_Construct_UClass_UCustomMovementComponent_NoRegister();
	ACTION3D_API UClass* Z_Construct_UClass_UCustomMovementComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
	UPackage* Z_Construct_UPackage__Script_Action3D();
// End Cross Module References
	DEFINE_FUNCTION(UCustomMovementComponent::execEndCrouch)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndCrouch();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomMovementComponent::execStartCrouch)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartCrouch();
		P_NATIVE_END;
	}
	void UCustomMovementComponent::StaticRegisterNativesUCustomMovementComponent()
	{
		UClass* Class = UCustomMovementComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndCrouch", &UCustomMovementComponent::execEndCrouch },
			{ "StartCrouch", &UCustomMovementComponent::execStartCrouch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCustomMovementComponent_EndCrouch_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMovementComponent_EndCrouch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement: Crouch" },
		{ "ModuleRelativePath", "CustomMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMovementComponent_EndCrouch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMovementComponent, nullptr, "EndCrouch", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomMovementComponent_EndCrouch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMovementComponent_EndCrouch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomMovementComponent_EndCrouch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCustomMovementComponent_EndCrouch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomMovementComponent_StartCrouch_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMovementComponent_StartCrouch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement: Crouch" },
		{ "ModuleRelativePath", "CustomMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMovementComponent_StartCrouch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMovementComponent, nullptr, "StartCrouch", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomMovementComponent_StartCrouch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMovementComponent_StartCrouch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomMovementComponent_StartCrouch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCustomMovementComponent_StartCrouch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCustomMovementComponent_NoRegister()
	{
		return UCustomMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCustomMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsCrouching_MetaData[];
#endif
		static void NewProp_bIsCrouching_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsCrouching;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Action3D,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCustomMovementComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomMovementComponent_EndCrouch, "EndCrouch" }, // 2421038613
		{ &Z_Construct_UFunction_UCustomMovementComponent_StartCrouch, "StartCrouch" }, // 3840846326
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CustomMovementComponent.h" },
		{ "ModuleRelativePath", "CustomMovementComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMovementComponent_Statics::NewProp_bIsCrouching_MetaData[] = {
		{ "Category", "Movement: Crouch" },
		{ "Comment", "// Crouch\n" },
		{ "ModuleRelativePath", "CustomMovementComponent.h" },
		{ "ToolTip", "Crouch" },
	};
#endif
	void Z_Construct_UClass_UCustomMovementComponent_Statics::NewProp_bIsCrouching_SetBit(void* Obj)
	{
		((UCustomMovementComponent*)Obj)->bIsCrouching = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomMovementComponent_Statics::NewProp_bIsCrouching = { "bIsCrouching", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomMovementComponent), &Z_Construct_UClass_UCustomMovementComponent_Statics::NewProp_bIsCrouching_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomMovementComponent_Statics::NewProp_bIsCrouching_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMovementComponent_Statics::NewProp_bIsCrouching_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomMovementComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMovementComponent_Statics::NewProp_bIsCrouching,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMovementComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCustomMovementComponent_Statics::ClassParams = {
		&UCustomMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCustomMovementComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMovementComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCustomMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomMovementComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCustomMovementComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCustomMovementComponent, 3588847195);
	template<> ACTION3D_API UClass* StaticClass<UCustomMovementComponent>()
	{
		return UCustomMovementComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCustomMovementComponent(Z_Construct_UClass_UCustomMovementComponent, &UCustomMovementComponent::StaticClass, TEXT("/Script/Action3D"), TEXT("UCustomMovementComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMovementComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
