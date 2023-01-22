import Foundation
import Pipa


func SampleExample(){
	let w1 = Window()
	Thread.sleep(forTimeInterval: 3.0)
	log("trace from swift", level: .trace)
	log("debug from swift", level: .debug)
	log("info from swift", level: .info)
	log("warning from swift", level: .warning)
	log("error from swift", level: .error)
	log("fatal from swift", level: .fatal)
}

SampleExample()

