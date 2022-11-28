  

int main(void)
{
    string answer = get_string("What's your name? ");
    string timeOfTheDay = get_string("Whats the time of the day? ");
    printf("Good %s, %s\n", timeOfTheDay, answer); // %s 는 해당 자리에 뭔가 다른걸 삽입한다는 의미, 두 번째 인자로 전달된 값을 해당 자리에 넣는다.
    // %s 개수만큼 인자를 순서대로 넣어주면 됨
}