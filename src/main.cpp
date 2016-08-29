#include "faceBomber.h"

int main() {
    FaceBomber *bomber = new FaceBomber();
    std::string imgPath("./imagesToBomb/example.jpeg");
    bomber->doFaceBomb(imgPath);

    delete bomber;
}