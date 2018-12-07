char keyCodes[256][2] = { }; //array of keys to swap

//this function adds a pair of keys to the array
int addKeys (int key1, int key2){
    for (int i = 0; i < sizeof(keyCodes); i++){
        if (keyCodes[i][0] == 0){
            keyCodes[i][0] = key1;
            keyCodes[i][1] = key2;
            return 0;
        }
    }
    return 1;//there is no free space in the array
}

//this function removes a pair of keys from the array
int removeKeys(int pair){
    if (pair < sizeof(keyCodes)){
        keyCodes[pair][0] = 0;
        keyCodes[pair][1] = 0;
        return 0;
    }
    return 1;//int pair is greater than the length of the array
}
