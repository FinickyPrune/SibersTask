//
//  ViewController.swift
//  Raccoon
//
//  Created by stajer on 23.04.2021.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet private weak var mainTable: UITableView!
    @IBOutlet private weak var addNewButton: UIButton!

    private var viewModel: ViewModel = ViewModel()
    
    private let cellIdentifier = "DefaultCell"
    private let addNewbuttonTitle = "Add New"
    private let tableName = "Table"

    override func viewDidLoad() {
        super.viewDidLoad()
        title  = tableName
        mainTable.dataSource = self
        mainTable.delegate = self
        viewModel.delegate = self
        mainTable.register(UITableViewCell.self, forCellReuseIdentifier: cellIdentifier)
        addNewButton.setTitle(addNewbuttonTitle, for: .normal)
        
    }
    
    @IBAction private func buttonDidPressed(_ sender: Any?) {
        viewModel.addButtonPressed()
    }
    
}

extension ViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return viewModel.getDataCount()
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier, for: indexPath)
        cell.textLabel?.text = viewModel.getStringValue(at: indexPath.row)
        return cell
    }
    
}

extension ViewController: UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        viewModel.didSelectValue(at: indexPath.row)
    }
    
    func tableView(_ tableView: UITableView, trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        let deleteAction = UIContextualAction(style: .destructive, title: "Delete", handler: {
            [weak self] (_, _, completion)  in
            self?.viewModel.removeFromData(at: indexPath.row)
         })
        
        let configuration = UISwipeActionsConfiguration(actions: [deleteAction])
        configuration.performsFirstActionWithFullSwipe = false
        return configuration
    }  
}

extension ViewController: ViewModelDelegate {
    
    func deleteCell(sender: ViewModel, at index: Int) {
        self.mainTable.deleteRows(at: [IndexPath(row: index, section: 0)], with: .right)
    }
    
    func updateCell(sender: ViewModel, at index: Int) {
        mainTable.reloadRows(at: [IndexPath(row: index, section: 0)], with: .automatic)
    }
    
    func insertCell(sender: ViewModel, at index: Int) {
        mainTable.insertRows(at: [IndexPath(row: index, section: 0)], with: .automatic)
    }
    
    func createEditorController(sender: ViewModel, with value: Int?) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        if let viewController = storyboard.instantiateViewController(identifier: "EditorViewController") as? EditorViewController {
            navigationController?.pushViewController(viewController, animated: true)
            let editorVM = EditorViewModel(value)
            editorVM.delegate = self
            viewController.editorViewModel = editorVM
        }
    }
    
}

extension ViewController: EditorViewModelDelegate {
    
    func didSubmitValue(_ seder: EditorViewModel, value: Int) {
        navigationController?.popViewController(animated: true)
        viewModel.didReceiveNewValue(value)
    }
    
}

