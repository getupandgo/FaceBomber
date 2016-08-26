#include "faceBomber.h"

int main() {
    FaceBomber *bomber = new FaceBomber();

    bomber->addImageToBomb("./imagesToBomb/example.jpeg");

    delete bomber;
}