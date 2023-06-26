// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SnakeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TEST0614_API ASnakeGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// �����ϸ鼭 ���� �ܰ� ���� ����� ���� �����ϴ� �Լ�
	UFUNCTION(BlueprintCallable)
	void CreateOutWall(int _Y, int _Z, FVector _TileSize, TSubclassOf<AActor> _WallType);

	FORCEINLINE FVector GetTileSize()
	{
		return TileSize;
	}

	FORCEINLINE FIntVector3 GetCount()
	{
		return TileCount;
	}

protected:
	void BeginPlay() override;

private:
	FVector TileSize;
	FIntVector3 TileCount;
	TArray<TArray<class AActor*>> AllMapActor;
};
