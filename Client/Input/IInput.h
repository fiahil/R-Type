
#pragma	once

enum GameInputKey {
	AuxUpKey,
	AuxDownKey,
	AuxLeftKey,
	AuxRightKey,
	UpKey,
	DownKey,
	LeftKey,
	RightKey,
	FireKey,
	UltimateKey
};

class IInput
{
public:
	virtual ~IInput() {};
	virtual void Bind(GameInputKey) = 0;
	virtual int getLastInput(GameInputKey) = 0;
	virtual bool isPressed(GameInputKey) = 0;
};