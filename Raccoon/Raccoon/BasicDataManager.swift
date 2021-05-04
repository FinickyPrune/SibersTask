//
//  DataManager.swift
//  Raccoon
//
//  Created by stajer on 04.05.2021.
//

import Foundation


class BasicDataManager {
    
    private var data: [Int] = []
    
    
    init() {
        data = (0..<100).map{_ in Int.random(in: 0..<100)}
    }
    
}

extension BasicDataManager: DataManager {
 
    func getStringValue(at index: Int) -> String {
        guard let intData = data[safe: index] else {
            fatalError("Index out of bounds.")
        }
        return String(intData)
    }
    
    func getDataCount() -> Int{
        return data.count
    }
 
    func removeValue(at index: Int) {
        data.remove(at: index)
    }
    
    func insertValue(_ value: Int, at index: Int) {
        data.insert(value, at: index)
    }
    
    func updateValue(for value: Int, at index: Int) {
        data[index] = value
    }
    

}
