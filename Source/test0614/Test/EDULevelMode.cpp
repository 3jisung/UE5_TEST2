// Fill out your copyright notice in the Description page of Project Settings.


#include "EDULevelMode.h"

AEDULevelMode::AEDULevelMode()
{

}

void AEDULevelMode::BeginPlay()
{
	// �𸮾��� C++ �����Ϸ��� ���� �����س���. 
	// AGameMode::BeginPlay();
	Super::BeginPlay();

	UE_LOG(LogTemp, Error, TEXT("Test"));
}