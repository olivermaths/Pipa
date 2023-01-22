import ARMKWindow

public class Window{
	var windowInstance : ARMK_Window;
	let windowName : String;

	public init(windowName: String = "Pipa" ){
		self.windowName = windowName
		windowInstance = armk_createWindow(windowName, 800, 600)
	}
	deinit {
		armk_destroyWindow(&windowInstance)
	}
}