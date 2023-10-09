// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WackyWizards/Wizard.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWizard() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_WackyWizards();
	WACKYWIZARDS_API UClass* Z_Construct_UClass_AWizard();
	WACKYWIZARDS_API UClass* Z_Construct_UClass_AWizard_NoRegister();
// End Cross Module References
	void AWizard::StaticRegisterNativesAWizard()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWizard);
	UClass* Z_Construct_UClass_AWizard_NoRegister()
	{
		return AWizard::StaticClass();
	}
	struct Z_Construct_UClass_AWizard_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWizard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_WackyWizards,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWizard_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWizard_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Wizard.h" },
		{ "ModuleRelativePath", "Wizard.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWizard_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Wizard.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWizard_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWizard, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWizard_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_AWizard_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWizard_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Wizard.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWizard_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWizard, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWizard_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_AWizard_Statics::NewProp_FollowCamera_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWizard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWizard_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWizard_Statics::NewProp_FollowCamera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWizard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWizard>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWizard_Statics::ClassParams = {
		&AWizard::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWizard_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AWizard_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWizard_Statics::Class_MetaDataParams), Z_Construct_UClass_AWizard_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWizard_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AWizard()
	{
		if (!Z_Registration_Info_UClass_AWizard.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWizard.OuterSingleton, Z_Construct_UClass_AWizard_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWizard.OuterSingleton;
	}
	template<> WACKYWIZARDS_API UClass* StaticClass<AWizard>()
	{
		return AWizard::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWizard);
	AWizard::~AWizard() {}
	struct Z_CompiledInDeferFile_FID_TEST_Wacky_Wizards_WackyWizards_Source_WackyWizards_Wizard_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TEST_Wacky_Wizards_WackyWizards_Source_WackyWizards_Wizard_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWizard, AWizard::StaticClass, TEXT("AWizard"), &Z_Registration_Info_UClass_AWizard, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWizard), 1561542171U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TEST_Wacky_Wizards_WackyWizards_Source_WackyWizards_Wizard_h_392697166(TEXT("/Script/WackyWizards"),
		Z_CompiledInDeferFile_FID_TEST_Wacky_Wizards_WackyWizards_Source_WackyWizards_Wizard_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TEST_Wacky_Wizards_WackyWizards_Source_WackyWizards_Wizard_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
