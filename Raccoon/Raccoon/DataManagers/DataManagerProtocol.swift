//
//  DataManagerProtocol.swift
//  Raccoon
//
//  Created by stajer on 05.05.2021.
//

import Foundation

protocol DataManager {
    
    func getDataCount() -> Int
    func getStringValue(at index: Int) -> String
    func removeValue(at index: Int)
    func insertValue<T>(_ value: T, at index: Int)
    func updateValue<T>(for value: T, at index: Int)
    func loadData(_ completion: @escaping () -> Void) 
        
}

extension DataManager {
    func loadData(_ completion: @escaping () -> Void) { completion() }
}
