// Fill out your copyright notice in the Description page of Project Settings.


#include "EDULevelMode.h"

AEDULevelMode::AEDULevelMode()
{

}

void AEDULevelMode::BeginPlay()
{
	// 언리얼이 C++ 컴파일러를 조금 수정해놔서. 
	// AGameMode::BeginPlay();
	Super::BeginPlay();

	UE_LOG(LogTemp, Error, TEXT("Test"));
}