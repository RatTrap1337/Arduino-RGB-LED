
struct Color_t {
    float r, g, b;
    
    static Color_t Red() {
        return Color_t { 255.f, 0.f, 0.f };
    }
    
    static Color_t Green() {
        return Color_t { 0.f, 255.f, 0.f };
    }
    
    static Color_t Blue() {
        return Color_t { 0.f, 0.f, 255.f };
    }
    
    Color_t& Modulate(const Color_t& To, int Time) {
        float r_step = (To.r - this->r) / Time;
        float g_step = (To.g - this->g) / Time;
        float b_step = (To.b - this->b) / Time;
        
        for (int i = 0; i <= Time; i++) {
            auto OutR = (int)map((this->r + r_step * i), 0.f, 255.f, 255.f, 0.f);
            auto OutG = (int)map((this->g + g_step * i), 0.f, 255.f, 255.f, 0.f);
            auto OutB = (int)map((this->b + b_step * i), 0.f, 255.f, 255.f, 0.f);
            
            analogWrite(9, OutR);
            analogWrite(10, OutG);
            analogWrite(11, OutB);
            
            delay(5);
        }
        
        // Update the current color to the target color
        this->r = To.r;
        this->g = To.g;
        this->b = To.b;
        
        return *this;
    }
};

void setup() { }

void loop() {
    Color_t::Red().Modulate(Color_t::Green(), 500)
                  .Modulate(Color_t::Blue(), 500)
                  .Modulate(Color_t::Red(), 500);
}
