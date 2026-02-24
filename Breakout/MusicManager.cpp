#include "MusicManager.h"
#include <iostream>

MusicManager::MusicManager()
{
    if (!backgroundMusic.openFromFile("audio/background_music.ogg")) {
        std::cerr << "Failed to load background music!" << std::endl;
    }
    if (!intenseMusic.openFromFile("audio/intense_music.ogg")) {
        std::cerr << "Failed to load intense music!" << std::endl;
    }
    backgroundMusic.setLoop(true);
    intenseMusic.setLoop(true);
    backgroundMusic.setVolume(100.0f);
    intenseMusic.setVolume(100.0f);
}

void MusicManager::playBackgroundMusic()
{
    if (_intenseMusicPlaying) {
        intenseMusic.stop();
        _intenseMusicPlaying = false;
    }
    backgroundMusic.setVolume(100.0f);
    backgroundMusic.play();
}

void MusicManager::playIntenseMusic()
{
    if (!_intenseMusicPlaying) {
        backgroundMusic.stop();
        intenseMusic.setVolume(100.0f);
        intenseMusic.play();
        _intenseMusicPlaying = true;
    }
}

void MusicManager::stopBackgroundMusic()
{
    backgroundMusic.stop();
}

void MusicManager::stopIntenseMusic()
{
    intenseMusic.stop();
    _intenseMusicPlaying = false;
}

bool MusicManager::isIntenseMusicPlaying() const
{
    return _intenseMusicPlaying && intenseMusic.getStatus() == sf::Music::Playing;
}

// Optional: Call this from your main update loop for fade-out support
void MusicManager::update(float dt)
{
    if (_fadingOut) {
        _fadeElapsed += dt;
        float ratio = std::min(_fadeElapsed / _fadeDuration, 1.0f);
        float newVolume = 100.0f * (1.0f - ratio);
        backgroundMusic.setVolume(newVolume);

        if (ratio >= 1.0f) 
        {
            backgroundMusic.stop();
            playIntenseMusic();
            _fadingOut = false;
        }
    }
}
