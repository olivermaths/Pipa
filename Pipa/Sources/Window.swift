import CWindow

public class Window{
	var swindow : SopranoWindow;
	let windowClassName: String;
	let windowName : String;

	public init(windowClassName: String = "Pipa Class", windowName: String = "Pipa" ){
		self.windowClassName = windowClassName
		self.windowName = windowName
		swindow = CreateSopranoWindow(windowClassName, windowName)
	}
	deinit {
		DestroySopranoWindow(&swindow, windowClassName)
	}
}

