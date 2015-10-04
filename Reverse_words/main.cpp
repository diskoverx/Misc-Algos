
//  Reverse words in a string
//  This is an inplace algorithm which doesn't require extra memory
//  Created by Nithin Raju Chandy on 10/4/15.
//  Copyright © 2015 Nithin Raju Chandy. All rights reserved.

#include <iostream>
#include<string>

using namespace std;


// helper function for the main reverse function to perform swap operations
void Reverse_word(char str[], int starter, int end)
{
    
    char temp;
    
    while(starter<end){
        
        temp=str[starter];
        str[starter]=str[end];
        str[end]=temp;
        
        starter++;
        end--;
    }
    
}



// Main Reversal Function
void Reverse_words_in_a_String(char str[])
{
    
    // Find the length of the string
    int len = strlen(str);
    
    // reverse entire string
    Reverse_word(str, 0, len-1);
    
    
    // First stage output
    cout<<"INPUT STRING AFTER REVERSAL (step 1): "<<str<<endl;
    
    
    // Second step is to reverse the individual words from the reversed string
    int start,end,current;
    
    end = len-1;
    start = 0;
    current = start;
    
    while (current<end)
    {
        start=current;
        
        // increment till end or a white space character to fetch word
        while(str[current]!='\0' && str[current]!= ' '){
            
            current++;
            
        }
        
        Reverse_word(str, start, current-1);
        
        // if white space, just move to the next one
        while(str[current]==' '){
            current=current+1;
        }
        
    }
    
    // Second stage output
    cout<<"INPUT STRING AFTER SECOND REVERSAL: "<<str<<endl;
    
    
}

int main()
{
    
    // First, we have to reverse the entire string.
    // Then, reverse each words in the reversed string.
    // Should handle boundary conditions
    
    char str[]= "  Hello, this is the test string  ";
    
    // printing string before manipulation
    cout<<"INPUT STRING BEFORE MAINPULATION: "<<str<<endl;
    
    // calling main reverse function
    Reverse_words_in_a_String(str);
    
    return 0;
    
    
}