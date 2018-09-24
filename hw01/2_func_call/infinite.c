int func(int x) {
    static int count = 0;
    return ++count && func(x++);
}

int main() {
    return func(0);
}
