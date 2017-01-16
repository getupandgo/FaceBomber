#include "faceBomber.h"

int main() {
    FaceBomber *bomber = new FaceBomber();
    std::string targetPhoto("/home/getupandgo/projects/FaceBomber/imagesToBomb/example.jpeg");
//    bomber->addFaceForBombing("harold", "/home/getupandgo/projects/FaceBomber/facesForBombing/harold.jpg");
    std::vector<std::string> masks;
    masks.push_back("/home/getupandgo/projects/FaceBomber/facesForBombing/harold.jpg");
    bomber->doUglyFaceBomb(targetPhoto, masks);

    delete bomber;
}