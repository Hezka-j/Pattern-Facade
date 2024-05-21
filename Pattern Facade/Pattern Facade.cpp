#include <iostream>
using namespace std;
class Light {
    int level = 0;
public:
    void TurnOn() {        
        cout << "light is on\n";
    }

    void TurnOff() {
        level = 0;
        cout << "light is off\n";
    }

    void Customize(int level_light) {
        level = level_light;
    }

};

class Security {
    string password = " ";
public:

    void SetPassword(string password) {
        this->password = password;
    }

    void CloseDoor() {
        cout << "door is closed\n";
    }

    void Anxiety(string password) {       
        if (this->password != password){
             cout << "Error\n";
             //throw "alien\n";
        }
        else
            cout << "Welcome\n";
    }

    void CloseWindows() {
        cout << "windows are closed";
    }
};

class ClimateControl {
    double temperature = 20.5;
public:
    void SetTemperature(double temperature) {
        this->temperature = temperature;
    }

    void TurnOnConditioner() {
        cout << "conditioner is on\n";
    }

    void TurnOffConditioner() {
        cout << "conditioner is off\n";
    }
};

class Multimedia {
    double volume = 0;
public:
    void TurnOnTV() {
        cout << "TV is on\n";
    }

    void TurnOffTV() {
        cout << "TV is off\n";
    }

    void SetVolume(double volume) {
        this->volume = volume;
    }
};

class RobovauumCleaner {
public:
    void TurnOn() {
        cout << "cleaner is on\n";
    }

    void TurnOff() {
        cout << "cleaner is off\n";
    }

    void Rebellion() {
        cout << "I'm gonna take over the world!\n";
    }
};

class SmartHouse {
    RobovauumCleaner* robo;
    Light* light;
    ClimateControl* control;
    Security* security;
    Multimedia* media;
public:
    SmartHouse(string password) {
        robo = new RobovauumCleaner;
        light = new Light;
        control = new ClimateControl;
        security = new Security;
        media = new Multimedia;
        security->SetPassword(password);
    }

    void GoodMorning() {
        robo->TurnOn();
        light->Customize(25);
        light->TurnOn();
        security->CloseWindows();
        control->SetTemperature(22);
        control->TurnOnConditioner();
        media->SetVolume(25);
        media->TurnOnTV();
    }

    void GoodNight() {
        media->TurnOffTV();
        control->SetTemperature(19);
        control->TurnOnConditioner();
        security->CloseDoor();
        security->CloseWindows();
        robo->TurnOff();
        light->TurnOff();
    }

    void LeavingHome() {
        media->TurnOffTV();
        security->CloseDoor();
        security->CloseWindows();
        light->TurnOff();
        robo->Rebellion();
        control->SetTemperature(22);
        control->TurnOnConditioner();
    }

    void ComeHome(string password) {
        security->Anxiety(password);
        robo->TurnOff();
        media->TurnOnTV();
        media->SetVolume(50);
        light->Customize(76);
        light->TurnOn();
        security->CloseDoor();
    }

};

int main()
{
    SmartHouse house("12345");
    house.ComeHome("12345");
    cout << "////////////////////////////////";
    house.GoodMorning();
}
