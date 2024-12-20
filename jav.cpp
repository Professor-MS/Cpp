#include <iostream>
#include <string>
#include <speechapi_cxx.h>
#include <windows.h>
#include <chrono>
#include <thread>

// Initialize the Speech API (both synthesis and recognition)
void speak(const std::string &text)
{
    // Replace with your Azure subscription key and region
    auto speechConfig = Microsoft::CognitiveServices::Speech::SpeechConfig::FromSubscription("YourAzureSubscriptionKey", "YourAzureRegion");
    auto synthesizer = Microsoft::CognitiveServices::Speech::SpeechSynthesizer::FromConfig(speechConfig);

    synthesizer->SpeakTextAsync(text).get();
}

std::string listen()
{
    std::string result;

    // Replace with your Azure subscription key and region
    auto speechConfig = Microsoft::CognitiveServices::Speech::SpeechConfig::FromSubscription("YourAzureSubscriptionKey", "YourAzureRegion");
    auto recognizer = Microsoft::CognitiveServices::Speech::SpeechRecognizer::FromConfig(speechConfig);

    auto result_async = recognizer->RecognizeOnceAsync();
    if (result_async.get().Reason == Microsoft::CognitiveServices::Speech::ResultReason::RecognizedSpeech)
    {
        result = result_async.get().Text();
    }
    else
    {
        result = "Sorry, I didn't catch that.";
    }

    return result;
}

// Implementing some commands
void open_website(const std::string &url)
{
    std::string command = "start " + url;
    system(command.c_str());
}

void play_music(const std::string &song_name)
{
    std::string music_folder = "C:\\Users\\msalm\\Music\\"; // Change to your music folder path
    std::string command = "start " + music_folder + song_name + ".mp3";
    system(command.c_str());
}

int main()
{
    speak("Hello, Professor! Jarvis is ready to receive commands.");

    while (true)
    {
        std::string command = listen();
        std::cout << "You said: " << command << std::endl;

        if (command == "hello jarvis")
        {
            speak("Hello, Professor! What can I do for you?");
        }
        else if (command == "open youtube")
        {
            open_website("https://www.youtube.com");
        }
        else if (command == "open google")
        {
            open_website("https://www.google.com");
        }
        else if (command == "play music")
        {
            speak("Playing your music.");
            play_music("So Lonely Song"); // Adjust the song name or make dynamic based on command
        }
        else if (command == "what time is it")
        {
            auto now = std::chrono::system_clock::now();
            auto now_time_t = std::chrono::system_clock::to_time_t(now);
            speak("The current time is " + std::string(ctime(&now_time_t)));
        }
        else if (command == "shut down the system")
        {
            speak("Shutting down the system.");
            system("shutdown /s /t 1");
        }
        else if (command == "lock my computer")
        {
            speak("Locking your computer.");
            system("rundll32.exe user32.dll,LockWorkStation");
        }
        else
        {
            speak("Sorry, I don't recognize that command.");
        }

        // Wait for a moment before accepting new input
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
