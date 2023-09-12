#include <planet096.h>

void app() {
  Planet096Scene scene;
  Planet096ProgressBar progressBar(&scene, 39, 38, 50, 8, 0, 100, 0);

  Planet096Text text(&scene, "Loading...");
  text.setLocation(36, 19);

  Planet096Widget widgets = createWidgets();
  widgets.progress_bar_ui = &progressBar;
  widgets.text_ui = &text;

  scene.setMainWidget(widgets);
  Planet096App::start(scene);

  delay(1000);
  for (int i = 0; i < 100; i++) {
    progressBar.setValue(i);
    delay(5);
  }
}