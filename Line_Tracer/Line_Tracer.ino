// 왼쪽 두개의 바퀴를 제어
#define M_ENA 3  // 모터드라이버 ENA 핀, 아두이노 우노 보드 디지털 3번 핀에 연결
#define M_IN1 4  // 모터드라이버 IN1 핀, 아두이노 우노 보드 디지털 4번 핀에 연결
#define M_IN2 5  // 모터드라이버 IN2 핀, 아두이노 우노 보드 디지털 5번 핀에 연결
// 오른쪽 두개의 바퀴를 제어
#define M_ENB 11 // 모터드라이버 ENB 핀, 아두이노 우노 보드 디지털 11번 핀에 연결
#define M_IN3 13 // 모터드라이버 IN1 핀, 아두이노 우노 보드 디지털 13번 핀에 연결
#define M_IN4 12 // 모터드라이버 IN2 핀, 아두이노 우노 보드 디지털 12번 핀에 연결

#define L_E 14 // 왼쪽 초음파센서 Echo
#define L_T 15 // 왼쪽 초음파센서 Trig
#define C_E 16  // 가운데 초음파센서 Echo
#define C_T 17  // 가운데 초음파센서 Trig
#define R_E 18 // 오른쪽 초음파센서 Echo
#define R_T 19 // 오르쪽 초음파센서 Trig

int motorA_vector = 1;  // DC모터의 회전방향이 반대일 시 1을 0으로
// "1"을 "0"으로 바꿔주면 DC모터의 회전방향이 바뀜.
void setup()  // 초기화
{
  Serial.begin(9600);
  pinMode(M_ENA, OUTPUT);  // ENA와 연결된 핀 출력 설정
  pinMode(M_IN1, OUTPUT);  // IN1과 연결된 핀 출력 설정
  pinMode(M_IN2, OUTPUT);  // IN2와 연결된 핀 출력 설정
  pinMode(M_ENB, OUTPUT);  // ENB와 연결된 핀 출력 설정
  pinMode(M_IN3, OUTPUT);  // IN3과 연결된 핀 출력 설정
  pinMode(M_IN4, OUTPUT);  // IN4와 연결된 핀 출력 설정
  pinMode(L_T, OUTPUT);
  pinMode(L_E, INPUT);
  pinMode(C_T, OUTPUT);
  pinMode(C_E, INPUT);
  pinMode(R_T, OUTPUT);
  pinMode(R_E, INPUT);
}
void loop()  // 무한루프
{
  ultra();
//  motor_back();
//  motor_stop();
//  motor_start();
//  motor_stop();
}

void motor_start(){
    // DC모터 정회전
  Serial.println("Front Start");
  digitalWrite(M_ENA, HIGH);  // 모터구동 ON
  digitalWrite(M_IN1, motorA_vector);  // IN1에 HIGH(or LOW)
  digitalWrite(M_IN2, !motorA_vector);  // IN2에 LOW(or HIGH)
  digitalWrite(M_ENB, HIGH);  // 모터구동 ON
  digitalWrite(M_IN3, motorA_vector);  // IN3에 HIGH(or LOW)
  digitalWrite(M_IN4, !motorA_vector);  // IN4에 LOW(or HIGH)
  delay(5000);  // 5초간 지연
  }

void motor_back(){
  // DC모터 역회전
  Serial.println("Rear Start");
  digitalWrite(M_ENA, HIGH);  // 모토구동 ON
  digitalWrite(M_IN1, !motorA_vector);  // IN1에 LOW(or HIGH)
  digitalWrite(M_IN2, motorA_vector);  // IN2에 HIGH(or LOW)
  digitalWrite(M_ENB, HIGH);  // 모터구동 ON
  digitalWrite(M_IN3, !motorA_vector);  // IN1에 LOW(or HIGH)
  digitalWrite(M_IN4, motorA_vector);  // IN2에 HIGH(or LOW)
  delay(5000);  // 5초간 지연
  }

void motor_stop(){
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

void ultra(){
  long lduration, ldistance, cduration, cdistance, rduration, rdistance;
  digitalWrite(L_T, LOW);
  delayMicroseconds(2);
  digitalWrite(L_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(L_T, LOW);
  digitalWrite(C_T, LOW);
  delayMicroseconds(2);
  digitalWrite(C_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(C_T, LOW);
  digitalWrite(R_T, LOW);
  delayMicroseconds(2);
  digitalWrite(R_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(R_T, LOW);

  lduration = pulseIn(L_E, HIGH);
  ldistance = lduration * 17 / 1000;
  Serial.print("Left Ultra: ");
  Serial.println(ldistance);
  
  cduration = pulseIn(C_E, HIGH);
  cdistance = cduration * 17 / 1000;
  Serial.print("Center Ultra: ");
  Serial.println(cdistance);
  
  rduration = pulseIn(R_E, HIGH);
  rdistance = rduration * 17 / 1000;
  Serial.print("Right Ultra: ");
  Serial.println(rdistance);
  delay(10);
  }
