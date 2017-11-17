#include "MeshShapeBaseActor.h"

AMeshShapeBaseActor::AMeshShapeBaseActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	FillMesh = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("FillMesh"));
	FillMesh->SetupAttachment(RootComponent);

	StrokeMesh = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("StrokeMesh"));
	StrokeMesh->SetupAttachment(RootComponent);

	Fill.bEnabled = true;
}

#if WITH_EDITOR
void AMeshShapeBaseActor::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
	Super::PostEditChangeChainProperty(PropertyChangedEvent);

	Update();
}
#endif

void AMeshShapeBaseActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	Update();
}