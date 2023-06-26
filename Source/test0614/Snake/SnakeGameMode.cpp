// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeGameMode.h"

void ASnakeGameMode::BeginPlay()
{
	Super::BeginPlay();

	int X = 3;
	int Y = 3;

	// [][][][][]
	// []      []
	// []      []
	// []      []
	// [][][][][]

}

void ASnakeGameMode::CreateOutWall(int _Y, int _Z, FVector _TileSize, TSubclassOf<AActor> _WallType)
{
	// 대부부느이 언리얼 엔진의 컴포넌트들이 들고 있는 
	// 3차원에서의 위치값을 세팅해주고 처리하기 위해서 주고받는 구조체 입니다.
	// F가 붙어있으면 구조체
	// FTransform Trans;
	//TPersistentVectorRegisterType<T> Rotation; 회전
	//TPersistentVectorRegisterType<T> Translation; 위치
	//TPersistentVectorRegisterType<T> Scale3D; 크기

	// s멀티바이트고 
	UE_LOG(LogTemp, Log, TEXT("%S(%u)> MapCreate Start"), __FUNCTION__, __LINE__);

	TileCount.Y = _Y;
	TileCount.Z = _Z;

	TileSize = _TileSize;


	// 
	AllMapActor.SetNumZeroed(TileCount.Z);
	// Num() => size()
	for (size_t z = 0; z < AllMapActor.Num(); z++)
	{
		AllMapActor[z].SetNum(TileCount.Y);
	}
	// Wall::StaticClass() <= 지금 내가 생성하려는 액터가 뭔지를 알려줍니다.
	// 이 내부에서 블루프린트 wall을 알수 있어야 한다.
	for (size_t i = 0; i < TileCount.Y; i++)
	{
		FTransform Trans;
		Trans.SetLocation({ 0, TileSize.Y * static_cast<float>(i), 0.0f });
		AActor* SpawnedActor0 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);

		Trans.SetLocation({ 0, TileSize.Y * static_cast<float>(i), TileSize.Z * static_cast<float>(TileCount.Z - 1) });
		AActor* SpawnedActor1 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);
	}

	for (size_t i = 0; i < TileCount.Z; i++)
	{
		FTransform Trans;
		Trans.SetLocation({ 0, 0, TileSize.Z * i });
		AActor* SpawnedActor0 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);

		Trans.SetLocation({ 0, TileSize.Y * static_cast<float>(TileCount.Y - 1), TileSize.Z * i });
		AActor* SpawnedActor1 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);
	}


}