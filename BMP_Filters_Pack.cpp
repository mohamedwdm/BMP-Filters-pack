#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
void saveImage ();
void invertimage ();
void lighten_darkenimage() ;
void rotateImage();
void BWimage() ;
void mergeImages();
void flipimage();
void mirror();
void shuffle();
void blur();

int main()
{
    int m;
    while (true) {
      cout << "====================================================\n";
      cout << "| Choose a filter:                                 |\n";
      cout << "|--------------------------------------------------|\n";
      cout << "| 1. Black and White Image Filter                  |\n";
      cout << "| 2. Inverting Image (Negative) filter             |\n";
      cout << "| 3. Merge Two Images filter                       |\n";
      cout << "| 4. Flip Image filter                             |\n";
      cout << "| 5. Rotate Image filter                           |\n";
      cout << "| 6. Darken or Lighten Image filter                |\n";
      cout << "| 7. Mirror Filter                                 |\n";
      cout << "| 8. Shuffle Filter                                |\n";
      cout << "| 9. Blur Filter                                   |\n";
      cout << "|--------------------------------------------------|\n";
      cout << "| 0. Exit                                          |\n";
      cout << "====================================================\n";
      cout << "Enter your choice: ";
      cin >> m;
        if (m == 0) {
            break;
        }
        switch(m) {
            case 1 :
                BWimage();
                break;
            case 2 :
                invertimage();
                break;
            case 3 :
                mergeImages();
                break;
            case 4 :
                flipimage();
                break;
            case 5 :
                rotateImage();
                break;
            case 6 :
                lighten_darkenimage();
                break;
            case 7 :
                mirror();
                break;
            case 8 :
                shuffle();
                break;

            case 9 :
                blur();
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                continue;
        }
        saveImage();
    }
    return 0;
}

//_________________________________________

void saveImage () {
   char imageFileName[100];
   // Get gray scale image target file name
   cout << "Enter the target image file name without .bmp: ";
   cin >> imageFileName;
   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
//_________________________________________
void BWimage() {
       char imageFileName[100];
       // Get gray scale image file name

   while(1){    
   cout << "Enter the source image file name without .bmp: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   
   if(readGSBMP(imageFileName, image) != 1){
    break;
   };
   }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
     if(image[i][j] > 127)
        image[i][j] = 255;
     else
        image[i][j] = 0;

    }
  }
}
//_________________________________________
void invertimage() {
          char imageFileName[100];
    // Get gray scale image file name
    while(1){    
      cout << "Enter the source image file name without .bmp: ";
      cin >> imageFileName;
      strcat (imageFileName, ".bmp");
      
      if(readGSBMP(imageFileName, image) != 1){
       break;
      };
      }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

image[i][j] = 255 - image[i][j];
    }
  }
}
//_________________________________________
void mergeImages() {
       char imageFileName[100];
        char imageFileName1[100];
      // Get gray scale 1st image file name
      while(1){    
        cout << "Enter the first image file name without .bmp: ";
        cin >> imageFileName;
        strcat (imageFileName, ".bmp");
        
        if(readGSBMP(imageFileName, image) != 1){
         break;
        };
        }
   // Get gray scale 2d image file name
   while(1){    
    cout << "Enter the second image file name without .bmp: ";
    cin >> imageFileName1;
    strcat (imageFileName1, ".bmp");
    
    if(readGSBMP(imageFileName1, image1) != 1){
     break;
    };
    }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      image[i][j] = (image[i][j] + image1[i][j]) / 2;
    }
  }
}
//_________________________________________
void flipimage()
{
    char imageFileName[100];
    // Get gray scale image file name
    while(1){    
      cout << "Enter the source image file name without .bmp: ";
      cin >> imageFileName;
      strcat (imageFileName, ".bmp");
      
      if(readGSBMP(imageFileName, image1) != 1){
       break;
      };
      }
 //choose vertical or horizontal .
  cout << "Enter 1 for Vertical, Enter 0 for Horizontal: ";
  int n;
  cin >> n;

  if (n)
  {
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        image2[i][j] = image1[SIZE - 1 - i][SIZE - 1 - j];
      }
    }
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        image[i][j] = image2[i][SIZE-1-j];
      }
    }
  }
  else
  {
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        image[i][j] = image1[i][SIZE - 1 - j];
      }
    }
  }
}
//_________________________________________
void rotateImage() {
       char imageFileName[100];
      // Get gray scale image file name
      while(1){    
        cout << "Enter the source image file name without .bmp: ";
        cin >> imageFileName;
        strcat (imageFileName, ".bmp");
        
        if(readGSBMP(imageFileName, image) != 1){
         break;
        };
        }
  unsigned char temp[SIZE][SIZE];
  int n;
  cout << "to rotate 90 press --> 1 ,  180 press --> 2 , 270 press --> 3  : ";
  cin >> n;
  n = 4-n;

  while (n) {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        temp[i][j] = image[i][j];
      }
    }

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        image[i][j] = temp[j][SIZE - i - 1];
      }
    }
    n--;
  }
}
//_________________________________________
void lighten_darkenimage() {
     char imageFileName[100];
    // Get gray scale image file name
    while(1){    
      cout << "Enter the source image file name without .bmp: ";
      cin >> imageFileName;
      strcat (imageFileName, ".bmp");
      
      if(readGSBMP(imageFileName, image) != 1){
       break;
      };
      }

   cout<<"for lighten press 1 , darken press 0 : ";
   int n; cin>> n ;
   if(n == 1){
     for (int i = 0; i < SIZE; i++) {
       for (int j = 0; j< SIZE; j++) {
          image[i][j] = (255 - image[i][j]  ) / 2 +  image[i][j] ;}
           }
          }
         else{
              for (int i = 0; i < SIZE; i++) {
       for (int j = 0; j< SIZE; j++) {
             image[i][j] =  image[i][j] /2;}
}
 }
}
void mirror(){
     char imageFileName[100];
    // Get gray scale image file name
    while(1){    
      cout << "Enter the source image file name without .bmp: ";
      cin >> imageFileName;
      strcat (imageFileName, ".bmp");
      
      if(readGSBMP(imageFileName, image) != 1){
       break;
      };
      }

    cout << "Please enter l for left or r for right or u for upper or d for down:\n";

    char a;
    cin >> a;
    if(a=='d' or a == 'D')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[SIZE-i][j];
            }
        }
    }
    if(a=='l' or a == 'L')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][SIZE-j] = image[i][j];
            }
        }
    }
    else if(a=='r' or a=='R')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][SIZE-j];
            }
        }
    }
    else if(a=='u' or a=='U')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[SIZE-i][j] = image[i][j];
            }
        }
    }

}
void shuffle(){
     char imageFileName[100];
    // Get gray scale image file name
    while(1){    
      cout << "Enter the source image file name without .bmp: ";
      cin >> imageFileName;
      strcat (imageFileName, ".bmp");
      
      if(readGSBMP(imageFileName, image) != 1){
       break;
      };
      }
int q1, q2, q3, q4;
    cout << "enter ordering of image quarters like (1 3 2 4): ";
    cin >> q1 >> q2 >> q3 >> q4;
    for(int i = 0; i < 127; i++){
        for(int j = 0; j < 127; j++){
            if(q1 == 1){
                image2[i][j] = image[i][j];
            }
            else if(q1 == 2){
                image2[i][j] = image[i][j+127];
            }
            else if(q1 == 3){
                image2[i][j] = image[i+127][j];
            }
            else if(q1 == 4){
                image2[i][j] = image[i+127][j+127];
            }
        }
    }
    for(int i = 0; i < 127; i++) {
        for (int j = 127; j < 256; j++) {
            if (q2 == 1) {
                image2[i][j] = image[i][j-127];
            } else if (q2 == 2) {
                image2[i][j] = image[i][j];
            } else if (q2 == 3) {
                image2[i][j] = image[i+127][j-127];
            } else if (q2 == 4) {
                image2[i][j] = image[i+127][j];
            }
        }
    }
    for(int i = 127; i < 256; i++) {
        for (int j = 0; j < 127; j++) {
            if (q3 == 1) {
                image2[i][j] = image[i-127][j];
            } else if (q3 == 2) {
                image2[i][j] = image[i-127][j+127];
            } else if (q3 == 3) {
                image2[i][j] = image[i][j];
            } else if (q3 == 4) {
                image2[i][j] = image[i][j+127];
            }
        }
    }
    for(int i = 127; i < 256; i++) {
        for (int j = 127; j < 256; j++) {
            if (q4 == 1) {
                image2[i][j] = image[i-127][j-127];
            } else if (q4 == 2) {
                image2[i][j]  = image[i-127][j];
            } else if (q4 == 3) {
                image2[i][j]  = image[i][j-127];
            } else if (q4 == 4) {
                image2[i][j]  = image[i][j];
            }
        }
    }
    for(int i =0 ; i < SIZE ; ++i){
        for(int j = 0 ; j < SIZE ; ++j){
            image[i][j] = image2[i][j];
        }
    }
}
void blur() {
    char imageFileName[100];
    // Get gray scale image file name
    while(1){    
      cout << "Enter the source image file name without .bmp: ";
      cin >> imageFileName;
      strcat (imageFileName, ".bmp");
      
      if(readGSBMP(imageFileName, image) != 1){
       break;
      };
      }
  // Create a temporary image array to store the blurred image
  unsigned char image1[SIZE][SIZE];

  // Iterate over each pixel in the image
  for (int i = 1; i < SIZE ; i++) {
    for (int j = 1; j < SIZE ; j++) {
      // Calculate the average of the surrounding pixels
      int sum = 0;
      for (int k = -3; k <= 3; k++) {
        for (int l = -3; l <= 3; l++) {
          sum += image[i + k][j + l];
        }
      }
      image1[i][j] = sum / 47; // Divide by 25 to get the average
    }
  }

  // Copy the blurred image from the temporary array to the original array
  for (int i = 1; i < SIZE ; i++) {
    for (int j = 1; j < SIZE ; j++) {
      image[i][j] = image1[i][j];
    }
  }
}
