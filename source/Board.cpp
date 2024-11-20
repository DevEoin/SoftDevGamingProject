#include "Board.h"

Board::Board() {
    this->size = 10;
    for(auto ship : ships) {
        ship = nullptr;
    }
}

void Board::printGrid(){
  std::cout<<std::endl;
  std::cout<<" ";
  int i=1,j;

  std::cout<<std::endl;
  for(i = 0; i <= 2*size; i++){
    if(i%2!=0)
        std::cout<<size - i/2 ;
    
    for(j = 0; j <= 2*size; j++){
      if(i%2==0)
      {
        if(j==0)
            std::cout<<" ";
        if(j%2==0)
            std::cout<<" ";
        else std::cout<<"---";
      }
      else{
        if(j%2==0)
            std::cout<<"|";
        else {
            int pos = i/2*size + j/2;
            bool foundPiece = false;
            for (const auto piece : pieces)
            {
                if (piece->GetPos() == pos )
                {
                    std::cout<< " " << piece->GetName()  <<" "; // here is where we print the values i/2*size + j/2 
                    foundPiece = true;
                }
            }   
            if (!foundPiece)
            {
                std::cout<< "   "; 
            }     
        }
      }
    }

    std::cout<<std::endl;

  }
  std::cout<<" ";

  // print last row with numbers
  for(j = 0, i = 0; j <= 4*size; j++){
    if(j%4==2)
        std::cout<<(char)('A' + i++); // printing letters on the left
    else std::cout<<" ";
  }
  std::cout<<std::endl;
}