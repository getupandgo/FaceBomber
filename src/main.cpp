#include "faceBomber.h"

int main() {
    FaceBomber *bomber = new FaceBomber();
    std::string imgPath("/home/getupandgo/projects/FaceBomber/imagesToBomb/example.jpeg");
    bomber->addFaceForBombing("harold", "/home/getupandgo/projects/FaceBomber/facesForBombing/harold.jpg");
    bomber->doFaceBomb(imgPath);

    delete bomber;
}