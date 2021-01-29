typedef struct { //This creates a new type
    int x, y, z;
    char c;
} bunch_t; //This is the name of the struct
           //Copy everything above here to create a structure


//This function uses pass-by-reference      //This changes the original and does not copy
void increaseBunch_p(bunch_t *inputBunch_p) //Notice that there is a * in front of inputBunch making it a pointer
{         //Pointers all still have a value in the memory, but that value is literally the address of the original value
    inputBunch_p->x = inputBunch_p->x + 1;
    inputBunch_p->y = inputBunch_p->y + 1;
    inputBunch_p->z = inputBunch_p->z + 1;
    inputBunch_p->c = inputBunch_p->c + 1;
}

// This function uses pass-by-value
bunch_t increaseBunch(bunch_t inputBunch) //This automatically creates a copy when entering the function using more memory
{
    bunch_t outputBunch;
    outputBunch.x = inputBunch.x+1;
    outputBunch.y = inputBunch.y+1;
    outputBunch.z = inputBunch.z+1;
    outputBunch.c = inputBunch.c+1;

    return outputBunch;
}

int main(void)
{

    bunch_t myBunch = {1, 2, 3, '7'};  //'7' indicates that the 7 is a character

    myBunch.x = 5; //This will change the of x inside of the myBunch

    bunch_t newBunch = increaseBunch(myBunch); //This goes back to the function that is on line 18
    //Once you are inside of a function the debugger will show you things that are local to that function

    newBunch.c = 5;     //This changes the value of c inside new bunch
    newBunch.x = 10;

    bunch_t *newBunch_p = &newBunch;
    (*newBunch_p).x = 5; // This line and the one below it are exactly the same.
    newBunch_p->x = 5;  // They both modify the member x of the struct that the pointer is pointing to.

    increaseBunch_p(&newBunch);


    while (1);
}
