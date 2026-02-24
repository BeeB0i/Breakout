#pragma once
#include <SFML/Audio.hpp>

class MusicManager
{ public:

	MusicManager();
	void playBackgroundMusic();
	void playIntenseMusic();
	void stopBackgroundMusic();
	void stopIntenseMusic();
	bool isIntenseMusicPlaying() const;

	void update(float dt);

private:

	sf::Music backgroundMusic;
	sf::Music intenseMusic;
	bool _intenseMusicPlaying = false;

	// For fade-out (optional)
	bool _fadingOut = false;
	float _fadeDuration = 1.0f;
	float _fadeElapsed = 0.0f;
};

