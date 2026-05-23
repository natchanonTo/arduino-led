# Arduino LED Serial Control

โปรเจคนี้เป็น Arduino sketch สำหรับควบคุม LED 3 ดวงผ่าน Serial Monitor โดยสามารถสั่งเปิดหรือปิด LED แต่ละดวงได้จากคอมพิวเตอร์ ไม่ได้ให้ไฟกระพริบอัตโนมัติแล้ว แต่จะรอรับคำสั่งจากผู้ใช้แทน

## ไฟล์ในโปรเจค

- `sketch_may18a.ino` - โค้ดหลักของ Arduino
- `README.md` - คำอธิบายโปรเจคและวิธีใช้งาน

## อุปกรณ์ที่ใช้

- Arduino board เช่น Arduino Uno
- LED 3 ดวง
- Resistor สำหรับ LED แต่ละดวง เช่น 220 ohm หรือ 330 ohm
- Jumper wires
- Breadboard
- สาย USB สำหรับต่อ Arduino เข้ากับคอมพิวเตอร์

## การต่อวงจร

ต่อ LED เข้ากับขา digital ของ Arduino ดังนี้

| LED | Arduino Pin |
| --- | --- |
| LED ดวงที่ 1 | Pin 5 |
| LED ดวงที่ 2 | Pin 7 |
| LED ดวงที่ 3 | Pin 9 |

ตัวอย่างการต่อ LED แต่ละดวง:

1. ขา Anode หรือขายาวของ LED ต่อผ่าน resistor ไปยัง pin ที่ต้องการ เช่น pin 5
2. ขา Cathode หรือขาสั้นของ LED ต่อไปที่ GND

ควรใช้ resistor กับ LED ทุกดวงเพื่อจำกัดกระแสและป้องกัน LED เสีย

## หลักการทำงานของโค้ด

ในฟังก์ชัน `setup()` โปรแกรมจะเริ่ม Serial communication ที่ความเร็ว `9600 baud` และตั้งค่า pin `5`, `7`, และ `9` เป็น `OUTPUT`

```cpp
Serial.begin(9600);
pinMode(7, OUTPUT);
pinMode(9, OUTPUT);
pinMode(5, OUTPUT);
```

หลังจากนั้นจะสั่งให้ LED ทุกดวงดับตอนเริ่มต้น

```cpp
digitalWrite(5, LOW);
digitalWrite(7, LOW);
digitalWrite(9, LOW);
```

ในฟังก์ชัน `loop()` โปรแกรมจะตรวจสอบว่ามีข้อความถูกส่งมาจาก Serial Monitor หรือไม่ ถ้ามีคำสั่งเข้ามา โปรแกรมจะอ่านคำสั่ง ตัดช่องว่างด้านหน้าและท้ายข้อความ แล้วแปลงเป็นตัวพิมพ์เล็ก เพื่อให้รับคำสั่งได้ง่ายขึ้น

```cpp
String command = Serial.readStringUntil('\n');
command.trim();
command.toLowerCase();
```

จากนั้นโปรแกรมจะเปรียบเทียบคำสั่ง เช่น `5 on`, `5 off`, `all on`, หรือ `all off` แล้วสั่งเปิดหรือปิด LED ตามคำสั่งนั้น

## วิธีใช้งาน

1. เปิดโปรเจคนี้ใน Arduino IDE
2. เลือกบอร์ด Arduino และ port ให้ถูกต้อง
3. Upload โค้ด `sketch_may18a.ino` ลงบอร์ด
4. เปิด Serial Monitor
5. ตั้ง baud rate เป็น `9600`
6. พิมพ์คำสั่งเพื่อเปิดหรือปิด LED

## คำสั่งที่ใช้ได้

| คำสั่ง | ผลลัพธ์ |
| --- | --- |
| `5 on` | เปิด LED ที่ pin 5 |
| `5 off` | ปิด LED ที่ pin 5 |
| `7 on` | เปิด LED ที่ pin 7 |
| `7 off` | ปิด LED ที่ pin 7 |
| `9 on` | เปิด LED ที่ pin 9 |
| `9 off` | ปิด LED ที่ pin 9 |
| `all on` | เปิด LED ทุกดวง |
| `all off` | ปิด LED ทุกดวง |

ถ้าพิมพ์คำสั่งที่ไม่มีในรายการ โปรแกรมจะแสดงข้อความ `Unknown command`

## ตัวอย่างการใช้งาน

เปิด LED ที่ pin 5:

```text
5 on
```

ปิด LED ที่ pin 5:

```text
5 off
```

เปิด LED ทุกดวง:

```text
all on
```

ปิด LED ทุกดวง:

```text
all off
```

## หมายเหตุ

- ต้องเปิด Serial Monitor และตั้ง baud rate เป็น `9600` ให้ตรงกับ `Serial.begin(9600)`
- ถ้าส่งคำสั่งแล้วไม่มีผล ให้ตรวจสอบว่าเลือก line ending ใน Serial Monitor ให้ส่ง newline หรือกด Enter หลังพิมพ์คำสั่ง
- ถ้า LED ไม่ติด ให้ตรวจสอบขั้ว LED, resistor, สาย GND และ pin ที่ต่อกับ Arduino
