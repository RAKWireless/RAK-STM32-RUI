extern void setup();
extern void loop();

extern "C" void rui_setup()
{
  setup();
}

extern "C" void rui_loop()
{
  loop();
}
