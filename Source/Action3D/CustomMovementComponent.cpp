// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"


//=========================================
//             ����������
//=========================================

UCustomMovementComponent::UCustomMovementComponent()
{
	bIsCrouching = false;
}



// ���� �������� ������������ �������, ����� ��������...
void UCustomMovementComponent::StartCrouch()
{
	bIsCrouching = true;
	Crouch();
}

// ... � ����� ������.
void UCustomMovementComponent::EndCrouch()
{
	bIsCrouching = false;
	UnCrouch();
}