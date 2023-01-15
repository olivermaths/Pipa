// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Sandbox",
    products: [
        .executable(name: "Pipa", targets: ["Sandbox"]),
        .library(name: "Pipa", targets: ["Pipa"]),
        .library(name: "CWindow", targets: ["CWindow"])
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.    
        .executableTarget(
                name: "Sandbox",
                dependencies: [
                    "Pipa",
                ],
                path: "Sandbox/Sources"
        ),
        .target(
            name: "Pipa",
            dependencies: [
               "CWindow"
            ],
            path: "Pipa/Sources"
        ),
        .target(
            name: "CWindow",
            path: "Soprano/Sources/CWindow",
            linkerSettings: [
            .linkedLibrary("user32"),
            .linkedLibrary("gdi32"),
            .linkedLibrary("kernel32")
        ]
        ),
        .testTarget(
            name: "PipaTest",
            dependencies: ["Pipa"],
            path: "Pipa/Tests"
        ),
        .testTarget(
            name: "SopranoTest",
            dependencies: ["CWindow"],
            path: "Soprano/Tests"
        )
    ]
)
