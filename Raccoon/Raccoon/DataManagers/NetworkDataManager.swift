//
//  DataManager.swift
//  Raccoon
//
//  Created by stajer on 04.05.2021.
//

import Foundation


struct User: Codable {
    
    var userId: String
    var id: String
    var title: String
    var body: String
    
}

class NetworkDataManager {
    
    private var userArray: [User] = []
    
    init() {
        
        
    }
    
}

extension NetworkDataManager: DataManager {
 
    func getStringValue(at index: Int) -> String {
        return userArray[index].title
    }
    
    func getDataCount() -> Int{
        return userArray.count
    }
 
    func removeValue(at index: Int) {
        
    }
    
    func insertValue(_ value: Int, at index: Int) {
        
    }
    
    func updateValue(for value: Int, at index: Int) {
        
    }
    

}
