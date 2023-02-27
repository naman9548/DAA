int heightChecker(int* heights, int heightsSize){
int array[heightsSize];
for(int i=0;i<heightsSize;i++){
    array[i]=heights[i];
}
for(int i=0;i<heightsSize;i++){
    for(int j=0;j<heightsSize-i-1;j++){
        if(array[j]>array[j+1]){
            int t=array[j];
            array[j]=array[j+1];
            array[j+1]=t;
        }
    }
}
int count=0;
for(int i=0;i<heightsSize;i++){
    if(heights[i]!=array[i])
        count++;
}
return count;
}
