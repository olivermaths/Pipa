import CWindow

public class Window{
	var swindow : SopranoWindow;
	let windowName : String;

	public init(windowName: String = "Pipa" ){
		self.windowName = windowName
		swindow = createSopranoWindow(windowName, 800, 600)
		print(swindow.data.height)
	}
	deinit {
		destroySopranoWindow(&swindow)
	}
}