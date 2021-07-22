/*
for min
*/
int lo = 0, hi = 1e9;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (f(mid)) hi = mid;
    else lo = mid + 1;
}


/*for max
*/
int lo = 0, hi = 1e9;
while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (f(mid)) lo = mid;
    else hi = mid - 1;
}
