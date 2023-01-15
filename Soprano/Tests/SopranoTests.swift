import XCTest
@testable import CWindow

final class sopranoTests: XCTestCase {
    func testWindowCreation() throws {
       let w1 = CreateSopranoWindow("TEST CLASS", "TEST")
       XCTAssertNotEqual(w1.hwnd, nil, "Failed to create Windows Win32")
       XCTAssertNotEqual(w1.instance, nil, "Failed to create Instance Win32")
    }

}
