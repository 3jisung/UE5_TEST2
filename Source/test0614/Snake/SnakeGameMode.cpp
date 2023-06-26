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
	// ��κδ��� �𸮾� ������ ������Ʈ���� ��� �ִ� 
	// 3���������� ��ġ���� �������ְ� ó���ϱ� ���ؼ� �ְ�޴� ����ü �Դϴ�.
	// F�� �پ������� ����ü
	// FTransform Trans;
	//TPersistentVectorRegisterType<T> Rotation; ȸ��
	//TPersistentVectorRegisterType<T> Translation; ��ġ
	//TPersistentVectorRegisterType<T> Scale3D; ũ��

	// s��Ƽ����Ʈ�� 
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
	// Wall::StaticClass() <= ���� ���� �����Ϸ��� ���Ͱ� ������ �˷��ݴϴ�.
	// �� ���ο��� �������Ʈ wall�� �˼� �־�� �Ѵ�.
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