#pragma once
#include "TextGo.h"
class uiStartTimer : public TextGo
{
protected:
	float duration = 3.f;
	float timer = duration;
	int ceilSecond;

public:

	void Init() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void Reset() override;

	inline void SetDuration(float asSecond) { duration = asSecond; }
	inline float GetDuration() const { return duration; }

};

