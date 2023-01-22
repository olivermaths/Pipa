import Foundation

public enum LogLevel: String {
    case debug = "[DEBUG]", trace = "[TRACE]"
    case info = "[INFO]", warning = "[WARNING]", error = "[ERROR]", fatal = "[FATAL]"
    var color : String {
        switch self {
            case .trace:   return "\u{001B}[38;2;38;214;231m"
            case .debug:   return "\u{001B}[38;2;154;131;240m"
            case .info:    return "\u{001B}[38;2;12;250;128m"
            case .warning: return "\u{001B}[38;2;250;205;0m"
            case .error:   return "\u{001B}[38;2;240;89;45m"
            case .fatal:   return "\u{001B}[38;2;255;0;0m"
        }
    }
}



public func log(_ message: String, level: LogLevel){
    let dateFormatter = DateFormatter()
    dateFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
    let date = dateFormatter.string(from: Date())
    print("\(date) \(level.color)\(level.rawValue) \(message)\u{001B}[0;0m")
}


