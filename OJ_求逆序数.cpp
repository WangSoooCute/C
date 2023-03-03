int reverse(int n){
    int reverse=0;
    while(n){
        reverse=reverse*10+n%10;
        n/=10;
    }
    return reverse;
}
