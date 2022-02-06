// 왼쪽 두개의 바퀴를 제어
#define M_ENA 3  // 모터드라이버 ENA 핀, 아두이노 우노 보드 디지털 3번 핀에 연결
#define M_IN1 4  // 모터드라이버 IN1 핀, 아두이노 우노 보드 디지털 4번 핀에 연결
#define M_IN2 5  // 모터드라이버 IN2 핀, 아두이노 우노 보드 디지털 5번 핀에 연결
// 오른쪽 두개의 바퀴를 제어
#define M_ENB 11 // 모터드라이버 ENB 핀, 아두이노 우노 보드 디지털 11번 핀에 연결
#define M_IN3 13 // 모터드라이버 IN1 핀, 아두이노 우노 보드 디지털 13번 핀에 연결
#define M_IN4 12 // 모터드라이버 IN2 핀, 아두이노 우노 보드 디지털 12번 핀에 연결

int motorA_vector = 1;  // DC모터의 회전방향이 반대일 시 1을 0으로
// "1"을 "0"으로 바꿔주면 DC모터의 회전방향이 바뀜.
void setup()  // 초기화
{
  Serial.begin(9600);
  Serial.println(M_ENA);
  pinMode(M_ENA, OUTPUT);  // ENA와 연결된 핀 출력 설정
  pinMode(M_IN1, OUTPUT);  // IN1과 연결된 핀 출력 설정
  pinMode(M_IN2, OUTPUT);  // IN2와 연결된 핀 출력 설정
  pinMode(M_ENB, OUTPUT);  // ENB와 연결된 핀 출력 설정
  pinMode(M_IN3, OUTPUT);  // IN3과 연결된 핀 출력 설정
  pinMode(M_IN4, OUTPUT);  // IN4와 연결된 핀 출력 설정 
}
void loop()  // 무한루프
{
  // DC모터 정회전
  Serial.println("Front Start");
  digitalWrite(M_ENA, HIGH);  // 모터구동 ON
  digitalWrite(M_IN1, motorA_vector);  // IN1에 HIGH(or LOW)
  digitalWrite(M_IN2, !motorA_vector);  // IN2에 LOW(or HIGH)
  digitalWrite(M_ENB, HIGH);  // 모터구동 ON
  digitalWrite(M_IN3, motorA_vector);  // IN3에 HIGH(or LOW)
  digitalWrite(M_IN4, !motorA_vector);  // IN4에 LOW(or HIGH)
  delay(5000);  // 5초간 지연
  // DC모터 정지
  Serial.println("Stop");
  digitalWrite(M_ENA, LOW);  // 모터구동 OFF
  digitalWrite(M_IN1, LOW);  // IN1에 LOW
  digitalWrite(M_IN2, LOW);  // IN2에 LOW
  digitalWrite(M_ENB, LOW);  // 모터구동 OFF
  digitalWrite(M_IN3, LOW);  // IN1에 LOW
  digitalWrite(M_IN4, LOW);  // IN2에 LOW
  delay(1000);  // 1초간 지연
  // DC모터 역회전
  Serial.println("Rear Start");
  digitalWrite(M_ENA, HIGH);  // 모토구동 ON
  digitalWrite(M_IN1, !motorA_vector);  // IN1에 LOW(or HIGH)
  digitalWrite(M_IN2, motorA_vector);  // IN2에 HIGH(or LOW)
  digitalWrite(M_ENB, HIGH);  // 모터구동 ON
  digitalWrite(M_IN3, !motorA_vector);  // IN1에 LOW(or HIGH)
  digitalWrite(M_IN4, motorA_vector);  // IN2에 HIGH(or LOW)
  delay(5000);  // 5초간 지연
  // DC모터 정지
  Serial.println("Stop");
  digitalWrite(M_ENA, LOW);  // 모터구동 OFF
  digitalWrite(M_IN1, LOW);  // IN1에 LOW
  digitalWrite(M_IN2, LOW);  // IN2에 LOW
  digitalWrite(M_ENB, LOW);  // 모터구동 OFF
  digitalWrite(M_IN3, LOW);  // IN1에 LOW
  digitalWrite(M_IN4, LOW);  // IN2에 LOW
  delay(1000);  // 1초간 지연
}
