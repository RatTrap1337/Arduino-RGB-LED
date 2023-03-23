
struct Color_t {
 
  float r,g,b;
  
  static Color_t Red() {
   
    return Color_t { 255.f, 0.f, 0.f };
  }
  
  static Color_t Green() {
   
    return Color_t { 0.f, 255.f, 0.f };
  }
  
  static Color_t Blue() {
   
    return Color_t { 0.f, 0.f, 255.f };
  }
};

void ModulateColor(Color_t From, Color_t To, int Time) {

  float r = (To.r - From.r ) / Time;
  float g = (To.g - From.g ) / Time;
  float b = (To.b - From.b ) / Time;
  
  for (int i = 0; i <= Time; i++) { 
    
    auto OutR = (int)map((From.r + r * i), 0.f, 255.f, 255.f, 0.f);
    auto OutG = (int)map((From.g + g * i), 0.f, 255.f, 255.f, 0.f);
    auto OutB = (int)map((From.b + b * i), 0.f, 255.f, 255.f, 0.f);
    
    analogWrite(9, OutR);
    analogWrite(10, OutG);
    analogWrite(11, OutB);
    
    delay(5);
  }
}

void setup() { }

void loop() {
  
  ModulateColor(Color_t::Red(), Color_t::Green(),500.f); 
  ModulateColor(Color_t::Green(), Color_t::Blue(), 500.f); 
  ModulateColor(Color_t::Blue(), Color_t::Red(), 500.f); 
}
