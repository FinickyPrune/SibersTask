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
    func insertValue(_ value: Int, at index: Int)
    func updateValue(for value: Int, at index: Int)
        
}
