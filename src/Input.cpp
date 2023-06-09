#include "Engine.hpp"

void Engine::Input()
{
    Event event;
    while (engine_window.pollEvent(event))
    {
        if(event.type == Event::EventType::Closed)
        {
            engine_window.close();
        }
        if(event.type == Event::KeyPressed)                 
        {
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                if(!MainMenu && !GameOver && !LoadNextLevel && !CreditMenu)                 //don't work if in main menu or game over menu or loading new level
                {
                    IsPaused = !IsPaused;
                    IsPlaying = !IsPlaying;
                }
            }
        }
        if(event.type == Event::MouseButtonPressed)
        {
            if(PlayButton.getPosition().intersects(mouseRect))          //Play Button
            {
                ButtonClickSound.play();    //play click sound
                GameMusic.play();           //play game music
                IsPlaying = true;
                MainMenu = false;
                GameOver = false;
                IsPaused = false;
                CreditMenu = false;
                NewLevelRequired = true;
            }
            if(QuitButton.getPosition().intersects(mouseRect))          //Quit Button
            {
                ButtonClickSound.play();    //play click sound
                engine_window.close();
            }
            if(ReturnToMainMenuButton.getPosition().intersects(mouseRect))  //Return Button
            {
                ButtonClickSound.play();    //play click sound
                GameMusic.stop();
                MainMenuMusic.play();       //play main menu music again
                GameOver = false;
                IsPaused = false;
                IsPlaying = false;
                CreditMenu = false;
                MainMenu = true;
                LM.setCurrentLevel(0);      //set level number to 0
                Player.resetHealth();       //reset player's health
                Score = 0;                  //reset score
            }
            if(RestartButton.getPosition().intersects(mouseRect))       //Restart button
            {
                ButtonClickSound.play();    //play click sound
                IsPlaying = true;
                MainMenu = false;
                GameOver = false;
                IsPaused = false;
            }
            if(ResumeButton.getPosition().intersects(mouseRect))        //Resume button
            {
                ButtonClickSound.play();    //play click sound
                IsPlaying = true;
                IsPaused = false;
            }
            if(CreditButton.getPosition().intersects(mouseRect))
            {
                ButtonClickSound.play();
                MainMenu = false;
                CreditMenu = true;
            }
        }
        if(event.type == Event::MouseMoved)
        {
            if(PlayButton.getPosition().intersects(mouseRect))          //PLay Button change color
            {
                PlayButton.changeColorRed();
                
            }else{
                PlayButton.changeColorWhite();
            }
            if(QuitButton.getPosition().intersects(mouseRect))          //Quit Button change color
            {
                QuitButton.changeColorRed();
            }else{
                QuitButton.changeColorWhite();
            }
            if(RestartButton.getPosition().intersects(mouseRect))          //Restart button change color
            {
                RestartButton.changeColorRed();
            }else{
                RestartButton.changeColorWhite();
            }
            if(ReturnToMainMenuButton.getPosition().intersects(mouseRect))  //Return button change color
            {
                ReturnToMainMenuButton.changeColorRed();
            }else{
                ReturnToMainMenuButton.changeColorWhite();
            }
            if(ResumeButton.getPosition().intersects(mouseRect))  //Resume button change color
            {
                ResumeButton.changeColorRed();
            }else{
                ResumeButton.changeColorWhite();
            }
            if(CreditButton.getPosition().intersects(mouseRect))
            {
                CreditButton.changeColorRed();
            }else{
                CreditButton.changeColorWhite();
            }
        }
        Player.handleInput();                   //Player control keys
    }
}
