// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

void UMyUserWidget::NativeConstruct()
{

	if (MyButton != nullptr) {
		nNumber = 0;
		Btn_Text->SetText(FText::FromString(TEXT("UI TEST")));
		MyButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnlyMyButtonClicked);
	}

}

void UMyUserWidget::OnlyMyButtonClicked()
{
	if (MyText) 
	{	
		nNumber++;
		UE_LOG(LogTemp, Warning, TEXT("Number: %d"),nNumber);
		MyText->SetText(FText::FromString(TEXT("Button Clicked!!")));
	}


}
