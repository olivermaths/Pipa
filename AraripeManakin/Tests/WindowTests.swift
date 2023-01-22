import XCTest
@testable import ARMKWindow

final class cwindowTests: XCTestCase {
    func testWindowCreation() throws {
       let w1 = armk_createWindow("TEST", 800, 600)
       XCTAssertNotEqual(w1.plaftormContext, nil, "Failed to create Windows Instance")
       XCTAssertEqual(w1.data.width, 800, "Failed to set Window width")
       XCTAssertEqual(w1.data.height, 600, "Failed to set Window height")
    }

}
